.setcpu "65816"
.segment "CODE"
.org $0EA2
map_control_0f0ea2:
    .byte $E1 ; previous-row copy count
    .byte $EB ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $E2 ; previous-row copy count
