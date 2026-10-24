.setcpu "65816"
.segment "CODE"
.org $E44B
map_control_0fe44b:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
