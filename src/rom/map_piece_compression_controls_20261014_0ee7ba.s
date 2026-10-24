.setcpu "65816"
.segment "CODE"
.org $E7BA
map_control_0ee7ba:
    .byte $E0 ; previous-row copy escape
    .byte $32 ; row-distance/count
