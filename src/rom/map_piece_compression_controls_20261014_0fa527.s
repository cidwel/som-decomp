.setcpu "65816"
.segment "CODE"
.org $A527
map_control_0fa527:
    .byte $E3 ; previous-row copy count
    .byte $EB ; backreference distance high bits
    .byte $02 ; distance low bit/count
