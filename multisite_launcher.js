/**
 * @file
 * The main JS file for running the Multisite Launcher
 *
 * The Multisite Launcher launches parameter strings across domains
 */


(function ($) {

Drupal.multisite_launcher = Drupal.multisite_launcher || {};
Drupal.multisite_launcher.sites = Drupal.multisite_launcher.sites || {};

Drupal.behaviors.multisite_launcher = {
  attach: function(context) {
    var
    ini = $('.multisite_launcher_str');
    if(!ini) return;

    $('[data-multisite-launcher-checkbox]',context).each(function(){

      var 
      num = $(this).attr('data-multisite-launcher-counter');
      site = this.getAttribute('data-multisite-launcher-checkbox');

      Drupal.multisite_launcher.sites[site] = {
        elem: this,
        lid: $(this).attr('data-multisite-launcher-link-id'),
        ini: ini[num]
      };

      num++;
    });
 }
};

Drupal.multisite_launcher.launch = function(){
  var
  all = Drupal.multisite_launcher.sites;

  for(var site in all) {
    var 
    obj = all[site],
    elm = obj.elem,
    chk = ($(elm).is(':checked')),
    lid = obj.lid,
    ini = obj.ini,
    val = $(obj.ini).val();
    
    tag = document.getElementById(lid);
    tag.setAttribute('href', 'http://' + site + '/' + val);

    if(!chk) continue;

    var
    clk = document.createEvent("MouseEvents");
    clk.initMouseEvent("click", false, true, window, 0, 0, 0, 0, 0, true, false, false, true, 0, null);
    tag.dispatchEvent(clk);
  }

  return false;
};

})(jQuery);