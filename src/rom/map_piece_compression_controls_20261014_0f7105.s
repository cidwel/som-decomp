.setcpu "65816"
.segment "CODE"
.org $7105
map_control_0f7105:
    .byte $EF ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
