.setcpu "65816"
.segment "CODE"
.org $A448
map_control_0fa448:
    .byte $F1 ; progressive-copy count
    .byte $E3 ; previous-row copy count
    .byte $EB ; backreference distance high bits
    .byte $02 ; distance low bit/count
