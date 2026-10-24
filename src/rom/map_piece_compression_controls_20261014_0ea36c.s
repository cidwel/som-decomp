.setcpu "65816"
.segment "CODE"
.org $A36C
map_control_0ea36c:
    .byte $EB ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $E1 ; previous-row copy count
