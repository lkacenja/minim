<?php
 
use Drupal\Core\Template\Attribute;

function minim_preprocess_html(&$v) {
  if (!$v['attributes'] instanceof Attribute) {
    $v['attributes'] = new Attribute();
  }
  $body_classes = array();
  $user = \Drupal::currentUser();
  $body_classes[] = $user->isAuthenticated() > 0 ? 'logged-in' : 'anonymous';
  $body_classes[] = \Drupal::service('path.matcher')->isFrontPage() ? 'front' : 'not-front'; 
  $body_classes[] = !empty($v['node_type']) ? 'node-type-' . $v['node_type'] : 'not-node';
  call_user_func_array(array($v['attributes'], 'addClass'), $body_classes);
}

