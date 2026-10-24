.setcpu "65816"
.segment "CODE"
.org $2E99
map_control_0c2e99:
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
