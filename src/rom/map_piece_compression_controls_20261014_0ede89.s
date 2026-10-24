.setcpu "65816"
.segment "CODE"
.org $DE89
map_control_0ede89:
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
