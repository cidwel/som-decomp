.setcpu "65816"
.segment "CODE"
.org $0218
map_control_0f0218:
    .byte $E0 ; previous-row copy escape
    .byte $82 ; row-distance/count
