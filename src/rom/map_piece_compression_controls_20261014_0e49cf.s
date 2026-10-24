.setcpu "65816"
.segment "CODE"
.org $49CF
map_control_0e49cf:
    .byte $ED ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $EB ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
