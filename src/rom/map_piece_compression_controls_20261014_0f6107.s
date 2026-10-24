.setcpu "65816"
.segment "CODE"
.org $6107
map_control_0f6107:
    .byte $E5 ; previous-row copy count
    .byte $EC ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $EF ; backreference distance high bits
    .byte $83 ; distance low bit/count
