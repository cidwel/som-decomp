.setcpu "65816"
.segment "CODE"
.org $483C
map_control_0f483c:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
