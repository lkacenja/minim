minim
=====


Minim is an extremely minimal foundation for a clean and sustainable Drupal site.
The idea is to seperate concerns as much as possible. Allow modules to harvest data, 
without formatting it. Massage data for use in templates in perspective preprocess
functions. Keep clean and minimal (beautiful) templates.

Minim does not use any css preprocessors or frameworks. When working with Minim
themers should rely on elegant markup and clean reusable css
to get the job done. Object Oriented CSS approach is suggested
(http://coding.smashingmagazine.com/2011/12/12/an-introduction-to-object-oriented-css-oocss).
In our experience, most of the need for preprocessors or frameworks
comes from inability to control markup. We can take control of markup by removing 
presentational elements from the logic layer and generously preprocessing our data.
What small additional convenience these tools provide (variables, functions, mixins)
can be achieved conceptually without the extra bloat and with the addition of
complete sustainability.

Minim includes a css file for CSS objects, resuable classes. See the media object for
an example (http://www.stubbornella.org/content/2010/06/25/the-media-object-saves-hundreds-of-lines-of-code).
Minim includes layout.css is for larger structural context and media.css for media queries.

Minim starts with only three regions. Feel free to add more.

Minim places CSS in the header and JS in the footer. The footer scripts
contain both header and footer scoped JS. Use the 'weight' and 'group'
options for drupal_add_js in order to position files within the
scripts variable.

To include scripts, use drupal_add_js in theme processors.
