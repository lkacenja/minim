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
  $body_classes[] = !empty($v['node_type']) ? 'node-type-' . $v['node_type'] . ' ' . 'node' : 'not-node';
  if ($front == FALSE) {
    $bits = explode('/', $_SERVER['REQUEST_URI']);
    $class = 'page-';
    foreach($bits AS $bit) {
      if (!empty($bit)) {
        $body_classes[] = $class .= str_replace('_', '-', $bit);
        $class .= '-';
      }
    }
  }

  call_user_func_array(array($v['attributes'], 'addClass'), $body_classes);
}

function minim_preprocess_field(&$v) {
  if (!$v['attributes'] instanceof Attribute) {
    $v['attributes'] = new Attribute($v['attributes']);
    $v['attributes']->addClass('field', str_replace('_', '-', $v['element']['#field_name']));
  }
}

function minim_preprocess_node(&$v) {
   if (!$v['content_attributes'] instanceof Attribute) {
    $v['content_attributes'] = new Attribute();
  }
  $body_classes = array();
  $body_classes[] = "clearfix";
  call_user_func_array(array($v['content_attributes'], 'addClass'), $body_classes);
}
