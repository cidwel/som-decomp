.setcpu "65816"
.segment "CODE"
.org $02D1
map_control_0f02d1:
    .byte $EC ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $EF ; backreference distance high bits
    .byte $03 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
