.setcpu "65816"
.segment "CODE"
.org $0644
map_control_0e0644:
    .byte $F2 ; progressive-copy count
    .byte $E2 ; previous-row copy count
    .byte $EB ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $DB ; same-value copy count/distance
