.setcpu "65816"
.segment "CODE"
.org $71EB
map_control_0f71eb:
    .byte $EC ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
