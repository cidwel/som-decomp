.setcpu "65816"
.segment "CODE"
.org $FB40
map_control_0cfb40:
    .byte $EB ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $E3 ; previous-row copy count
