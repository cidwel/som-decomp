.setcpu "65816"
.segment "CODE"
.org $99A0
map_control_0f99a0:
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
