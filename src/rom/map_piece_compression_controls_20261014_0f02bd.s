.setcpu "65816"
.segment "CODE"
.org $02BD
map_control_0f02bd:
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
    .byte $D9 ; same-value copy count/distance
