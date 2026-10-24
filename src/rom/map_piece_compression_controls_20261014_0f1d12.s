.setcpu "65816"
.segment "CODE"
.org $1D12
map_control_0f1d12:
    .byte $EB ; backreference distance high bits
    .byte $02 ; distance low bit/count
