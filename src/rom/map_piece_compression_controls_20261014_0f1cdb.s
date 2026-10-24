.setcpu "65816"
.segment "CODE"
.org $1CDB
map_control_0f1cdb:
    .byte $EF ; backreference distance high bits
    .byte $02 ; distance low bit/count
