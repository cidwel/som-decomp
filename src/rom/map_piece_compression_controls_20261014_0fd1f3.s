.setcpu "65816"
.segment "CODE"
.org $D1F3
map_control_0fd1f3:
    .byte $EB ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $ED ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E1 ; previous-row copy count
