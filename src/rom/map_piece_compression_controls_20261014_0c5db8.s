.setcpu "65816"
.segment "CODE"
.org $5DB8
map_control_0c5db8:
    .byte $E4 ; previous-row copy count
    .byte $EB ; backreference distance high bits
    .byte $02 ; distance low bit/count
