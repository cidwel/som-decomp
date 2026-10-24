.setcpu "65816"
.segment "CODE"
.org $B3DB
map_control_0db3db:
    .byte $E2 ; previous-row copy count
    .byte $EF ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $EE ; backreference distance high bits
    .byte $04 ; distance low bit/count
