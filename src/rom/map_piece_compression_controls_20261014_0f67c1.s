.setcpu "65816"
.segment "CODE"
.org $67C1
map_control_0f67c1:
    .byte $E3 ; previous-row copy count
    .byte $EB ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $EE ; backreference distance high bits
    .byte $02 ; distance low bit/count
