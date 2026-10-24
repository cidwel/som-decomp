.setcpu "65816"
.segment "CODE"
.org $CCF4
map_control_0dccf4:
    .byte $EB ; backreference distance high bits
    .byte $05 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
