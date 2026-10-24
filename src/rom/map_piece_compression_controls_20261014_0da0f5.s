.setcpu "65816"
.segment "CODE"
.org $A0F5
map_control_0da0f5:
    .byte $E4 ; previous-row copy count
    .byte $EC ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $EB ; backreference distance high bits
    .byte $83 ; distance low bit/count
