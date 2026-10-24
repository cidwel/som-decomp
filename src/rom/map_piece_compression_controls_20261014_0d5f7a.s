.setcpu "65816"
.segment "CODE"
.org $5F7A
map_control_0d5f7a:
    .byte $E8 ; backreference distance high bits
    .byte $0D ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
