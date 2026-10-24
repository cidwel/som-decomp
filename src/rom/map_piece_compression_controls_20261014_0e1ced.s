.setcpu "65816"
.segment "CODE"
.org $1CED
map_control_0e1ced:
    .byte $ED ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
