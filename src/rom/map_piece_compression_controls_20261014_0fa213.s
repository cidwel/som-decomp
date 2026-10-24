.setcpu "65816"
.segment "CODE"
.org $A213
map_control_0fa213:
    .byte $EF ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $0D ; distance low bit/count
