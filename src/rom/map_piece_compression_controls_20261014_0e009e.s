.setcpu "65816"
.segment "CODE"
.org $009E
map_control_0e009e:
    .byte $E2 ; previous-row copy count
    .byte $EB ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $EB ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E1 ; previous-row copy count
