.setcpu "65816"
.segment "CODE"
.org $075A
map_control_0e075a:
    .byte $F1 ; progressive-copy count
    .byte $E1 ; previous-row copy count
    .byte $E8 ; backreference distance high bits
    .byte $2A ; distance low bit/count
