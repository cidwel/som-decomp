.setcpu "65816"
.segment "CODE"
.org $207D
map_control_0f207d:
    .byte $E9 ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $E7 ; previous-row copy count
