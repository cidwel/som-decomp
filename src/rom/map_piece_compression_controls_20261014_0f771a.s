.setcpu "65816"
.segment "CODE"
.org $771A
map_control_0f771a:
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
