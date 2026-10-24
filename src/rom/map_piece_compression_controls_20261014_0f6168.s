.setcpu "65816"
.segment "CODE"
.org $6168
map_control_0f6168:
    .byte $E5 ; previous-row copy count
    .byte $EC ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $E3 ; previous-row copy count
