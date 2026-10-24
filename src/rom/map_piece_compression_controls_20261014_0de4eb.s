.setcpu "65816"
.segment "CODE"
.org $E4EB
map_control_0de4eb:
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
