.setcpu "65816"
.segment "CODE"
.org $DCA3
map_control_0edca3:
    .byte $EF ; backreference distance high bits
    .byte $8E ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $7F ; distance low bit/count
