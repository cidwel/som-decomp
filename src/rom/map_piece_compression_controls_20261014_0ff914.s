.setcpu "65816"
.segment "CODE"
.org $F914
map_control_0ff914:
    .byte $E6 ; previous-row copy count
