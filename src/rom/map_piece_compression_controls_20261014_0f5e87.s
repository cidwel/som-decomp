.setcpu "65816"
.segment "CODE"
.org $5E87
map_control_0f5e87:
    .byte $EF ; backreference distance high bits
    .byte $82 ; distance low bit/count
