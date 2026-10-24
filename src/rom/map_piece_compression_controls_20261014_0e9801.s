.setcpu "65816"
.segment "CODE"
.org $9801
map_control_0e9801:
    .byte $E0 ; previous-row copy escape
    .byte $88 ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $11 ; distance low bit/count
