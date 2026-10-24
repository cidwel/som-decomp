.setcpu "65816"
.segment "CODE"
.org $6C46
map_control_0e6c46:
    .byte $E8 ; backreference distance high bits
    .byte $1A ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $C7 ; row-distance/count
