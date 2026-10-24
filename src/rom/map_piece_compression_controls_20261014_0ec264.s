.setcpu "65816"
.segment "CODE"
.org $C264
map_control_0ec264:
    .byte $E0 ; previous-row copy escape
    .byte $16 ; row-distance/count
