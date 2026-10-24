.setcpu "65816"
.segment "CODE"
.org $E660
map_control_0de660:
    .byte $EB ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $0D ; distance low bit/count
