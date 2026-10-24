.setcpu "65816"
.segment "CODE"
.org $ECB3
map_control_0fecb3:
    .byte $EF ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
