.setcpu "65816"
.segment "CODE"
.org $B351
map_control_0fb351:
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $0E ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $2C ; row-distance/count
