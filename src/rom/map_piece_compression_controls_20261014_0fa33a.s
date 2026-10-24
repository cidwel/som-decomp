.setcpu "65816"
.segment "CODE"
.org $A33A
map_control_0fa33a:
    .byte $EF ; backreference distance high bits
    .byte $88 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
