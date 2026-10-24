.setcpu "65816"
.segment "CODE"
.org $460C
map_control_0d460c:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
    .byte $EF ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $8C ; distance low bit/count
