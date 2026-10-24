.setcpu "65816"
.segment "CODE"
.org $007C
map_control_0f007c:
    .byte $E0 ; previous-row copy escape
    .byte $91 ; row-distance/count
