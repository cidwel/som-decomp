.setcpu "65816"
.segment "CODE"
.org $790B
map_control_0d790b:
    .byte $E0 ; previous-row copy escape
    .byte $20 ; row-distance/count
