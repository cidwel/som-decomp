.setcpu "65816"
.segment "CODE"
.org $4AB7
map_control_0e4ab7:
    .byte $EF ; backreference distance high bits
    .byte $88 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
