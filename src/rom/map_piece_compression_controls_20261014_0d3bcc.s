.setcpu "65816"
.segment "CODE"
.org $3BCC
map_control_0d3bcc:
    .byte $EF ; backreference distance high bits
    .byte $02 ; distance low bit/count
