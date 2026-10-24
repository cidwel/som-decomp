.setcpu "65816"
.segment "CODE"
.org $5871
map_control_0f5871:
    .byte $ED ; backreference distance high bits
    .byte $02 ; distance low bit/count
