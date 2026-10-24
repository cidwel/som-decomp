.setcpu "65816"
.segment "CODE"
.org $CA29
map_control_0eca29:
    .byte $EF ; backreference distance high bits
    .byte $8B ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
