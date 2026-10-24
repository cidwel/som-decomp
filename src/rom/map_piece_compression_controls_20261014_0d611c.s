.setcpu "65816"
.segment "CODE"
.org $611C
map_control_0d611c:
    .byte $E9 ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $E4 ; previous-row copy count
