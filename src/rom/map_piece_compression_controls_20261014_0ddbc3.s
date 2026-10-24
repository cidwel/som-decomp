.setcpu "65816"
.segment "CODE"
.org $DBC3
map_control_0ddbc3:
    .byte $EF ; backreference distance high bits
    .byte $8B ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $7F ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $41 ; row-distance/count
