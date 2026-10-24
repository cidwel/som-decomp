.setcpu "65816"
.segment "CODE"
.org $6809
map_control_0d6809:
    .byte $E1 ; previous-row copy count
